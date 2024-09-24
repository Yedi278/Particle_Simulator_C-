#ifndef NDEBUG
#define LOG(x) std::cout << x << std::endl
#define LOG_ERROR(x) std::cerr << x << std::endl
#define LOG_RED(x) std::cout << "\033[1;31m" << x << "\033[0m" << std::endl
#define LOG_GREEN(x) std::cout << "\033[1;32m" << x << "\033[0m" << std::endl
#define LOG_YELLOW(x) std::cout << "\033[1;33m" << x << "\033[0m" << std::endl
#define LOG_BLUE(x) std::cout << "\033[1;34m" << x << "\033[0m" << std::endl

#else

#define LOG(x)
#define LOG_ERROR(x)
#define LOG_RED(x)
#define LOG_GREEN(x)
#define LOG_YELLOW(x)
#define LOG_BLUE(x)

#endif

#define WHITE 255, 255, 255
#define BLACK 0, 0, 0
#define RED 255, 0, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255

#define G_CONST 9.81