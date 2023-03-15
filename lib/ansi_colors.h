#define COLOR_RED "\033[31m"
#define COLOR_BLUE "\033[34m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"

#define COLOR_BOLD "\033[1m"
#define COLOR_RESET "\033[0m"

#define COLOR_INFO COLOR_BOLD COLOR_BLUE
#define COLOR_ERROR COLOR_BOLD COLOR_RED
#define COLOR_WARNING COLOR_BOLD COLOR_YELLOW
#define COLOR_SUCCESS COLOR_BOLD COLOR_GREEN

#define TEXT_BOLD(str) COLOR_BOLD str COLOR_RESET
#define TEXT_INFO(str) COLOR_INFO str COLOR_RESET
#define TEXT_ERROR(str) COLOR_ERROR str COLOR_RESET
#define TEXT_WARNING(str) COLOR_WARNING str COLOR_RESET
#define TEXT_SUCCESS(str) COLOR_SUCCESS str COLOR_RESET
