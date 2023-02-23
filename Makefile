##
# quadratic_equation
#

CC=clang++
CFLAGS=-c -D _DEBUG -ggdb3 -std=c++20 -Wall -Wextra -Weffc++ -Wcast-align -Wcast-qual -Wchar-subscripts -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -fcheck-new -fsized-deallocation -fstack-check -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -fPIE -O0
TARGET=bin
BUILD=build

all: $(TARGET)

$(TARGET): solve_quadratic_equation.o discriminant.o solve_linear_equation.o solve_equation.o read_stdin.o std_print.o main.o
	$(CC) $(BUILD)/solve_quadratic_equation.o $(BUILD)/discriminant.o $(BUILD)/solve_linear_equation.o $(BUILD)/solve_equation.o $(BUILD)/read_stdin.o $(BUILD)/std_print.o $(BUILD)/main.o -o $(TARGET)

# TODO: Huge amount of similar tasks producing object files. Can you make it neater?

solve_quadratic_equation.o: solve_quadratic_equation.c discriminant.o
	$(CC) $(CFLAGS) solve_quadratic_equation.c -o $(BUILD)/solve_quadratic_equation.o
discriminant.o: discriminant.c
	$(CC) $(CFLAGS) discriminant.c -o $(BUILD)/discriminant.o
solve_linear_equation.o: solve_linear_equation.c
	$(CC) $(CFLAGS) solve_linear_equation.c -o $(BUILD)/solve_linear_equation.o

# TODO: Why solve_equation.c depends on solve_linear.o and solve_quadratic_equation.o?
solve_equation.o: solve_equation.c solve_linear_equation.o solve_quadratic_equation.o
	$(CC) $(CFLAGS) solve_equation.c -o $(BUILD)/solve_equation.o
read_stdin.o: read_stdin.c
	$(CC) $(CFLAGS) read_stdin.c -o $(BUILD)/read_stdin.o
std_print.o: std_print.c
	$(CC) $(CFLAGS) std_print.c -o $(BUILD)/std_print.o
main.o: main.c solve_equation.o std_print.o
	$(CC) $(CFLAGS) main.c -o $(BUILD)/main.o

exec:
	./bin

clean:
	rm -rf bin $(BUILD)/*.o

# end
