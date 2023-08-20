
all: HireMe_O3 HireMe HireMe_Base_O3 HireMe_Base

HireMe_O3: clean_HireMe_O3
	gcc -Wall -Werror -Wextra HireMe.c -O3 -lm -o build/HireMe_O3

HireMe: clean_HireMe
	gcc -Wall -Werror -Wextra HireMe.c -lm -o build/HireMe

HireMe_Base_O3: clean_HireMe_Base_O3
	gcc -Wall -Werror -Wextra HireMe_Base.c -O3 -o build/HireMe_Base_O3

HireMe_Base: clean_HireMe_Base
	gcc -Wall -Werror -Wextra HireMe_Base.c -o build/HireMe_Base

clean: clean_HireMe_O3 clean_HireMe clean_HireMe_Base_O3 clean_HireMe_Base

clean_HireMe_O3:
	rm build/HireMe_O3 || true

clean_HireMe:
	rm build/HireMe || true

clean_HireMe_Base_O3:
	rm build/HireMe_Base_O3 || true

clean_HireMe_Base:
	rm build/HireMe_Base || true