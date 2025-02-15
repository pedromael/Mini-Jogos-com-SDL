#include <SDL2/SDL.h>
#include <vector>
#include <time.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int CELL_SIZE = 20;
const int GRID_WIDTH = SCREEN_WIDTH / CELL_SIZE;
const int GRID_HEIGHT = SCREEN_HEIGHT / CELL_SIZE;

enum Direction { UP, DOWN, LEFT, RIGHT };

struct SnakeSegment {
    int x, y;
};

class SnakeGame {
public:
    SnakeGame() : running(true), direction(RIGHT) {
        snake.push_back({GRID_WIDTH / 2, GRID_HEIGHT / 2});
        spawnFood();
    }

    void run() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) return;
        window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        while (running) {
            handleEvents();
            update();
            render();
            SDL_Delay(100);
        }

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<SnakeSegment> snake;
    SnakeSegment food;
    Direction direction;
    bool running;

    void handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP: if (direction != DOWN) direction = UP; break;
                    case SDLK_DOWN: if (direction != UP) direction = DOWN; break;
                    case SDLK_LEFT: if (direction != RIGHT) direction = LEFT; break;
                    case SDLK_RIGHT: if (direction != LEFT) direction = RIGHT; break;
                }
            }
        }
    }

    void update() {
        SnakeSegment newHead = snake.front();
        switch (direction) {
            case UP: newHead.y--; break;
            case DOWN: newHead.y++; break;
            case LEFT: newHead.x--; break;
            case RIGHT: newHead.x++; break;
        }

        if (newHead.x < 0 || newHead.x >= GRID_WIDTH || newHead.y < 0 || newHead.y >= GRID_HEIGHT) {
            running = false;
            return;
        }
        
        for (auto& segment : snake) {
            if (newHead.x == segment.x && newHead.y == segment.y) {
                running = false;
                return;
            }
        }
        
        snake.insert(snake.begin(), newHead);
        if (newHead.x == food.x && newHead.y == food.y) {
            spawnFood();
        } else {
            snake.pop_back();
        }
    }

    void render() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        for (auto& segment : snake) {
            SDL_Rect rect = {segment.x * CELL_SIZE, segment.y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            SDL_RenderFillRect(renderer, &rect);
        }

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect foodRect = {food.x * CELL_SIZE, food.y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
        SDL_RenderFillRect(renderer, &foodRect);

        SDL_RenderPresent(renderer);
    }

    void spawnFood() {
        food.x = rand() % GRID_WIDTH;
        food.y = rand() % GRID_HEIGHT;
    }
};

int main() {
    srand(time(nullptr));
    SnakeGame game;
    game.run();
    return 0;
}
