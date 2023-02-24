##
# quadratic_equation
#

CC=clang++
CFLAGS=-D _DEBUG -ggdb3 -std=c++20 -Wall -Wextra -Weffc++ -Wcast-align -Wcast-qual -Wchar-subscripts -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -fcheck-new -fsized-deallocation -fstack-check -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -fPIE -O0
TARGET=bin
BUILD=build

# Nooo! I meant you should read how to express .o compilations shorter in Makefile, not to get rid of them 
# You've just killed your incremental compilation (when you recompile only what has changed)

# If you've done this in a bigger project, you would have easily 100x compilation time 
all:
	$(CC) $(CFLAGS) solve_quadratic_equation.cpp solve_linear_equation.cpp solve_equation.cpp read_coefficients.cpp print_solution.cpp main.cpp -o $(TARGET)

exec:
	./bin

clean:
	rm -f bin

# end
