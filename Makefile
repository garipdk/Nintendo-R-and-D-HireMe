
all: HireMe_Ofast HireMe_O3 HireMe HireMe_Base_Ofast HireMe_Base_O3 HireMe_Base HireMe_Ofast_mn HireMe_O3_mn HireMe_mn HireMe_Base_Ofast_mn HireMe_Base_O3_mn HireMe_Base_mn

HireMe_Ofast: clean_HireMe_Ofast
	gcc -Wall -Werror -Wextra HireMe.c -Ofast -lm -o build/HireMe_Ofast

HireMe_O3: clean_HireMe_O3
	gcc -Wall -Werror -Wextra HireMe.c -O3 -lm -o build/HireMe_O3

HireMe: clean_HireMe
	gcc -Wall -Werror -Wextra HireMe.c -lm -o build/HireMe

HireMe_Base_Ofast: clean_HireMe_Base_Ofast
	gcc -Wall -Werror -Wextra HireMe_Base.c -Ofast -o build/HireMe_Base_Ofast

HireMe_Base_O3: clean_HireMe_Base_O3
	gcc -Wall -Werror -Wextra HireMe_Base.c -O3 -o build/HireMe_Base_O3

HireMe_Base: clean_HireMe_Base
	gcc -Wall -Werror -Wextra HireMe_Base.c -o build/HireMe_Base


HireMe_Ofast_mn: clean_HireMe_Ofast_mn
	gcc -Wall -Werror -Wextra HireMe.c -Ofast -march=native -lm -o build/HireMe_Ofast_mn

HireMe_O3_mn: clean_HireMe_O3_mn
	gcc -Wall -Werror -Wextra HireMe.c -O3 -march=native -lm -o build/HireMe_O3_mn

HireMe_mn: clean_HireMe_mn
	gcc -Wall -Werror -Wextra HireMe.c -lm -march=native -o build/HireMe_mn

HireMe_Base_Ofast_mn: clean_HireMe_Base_Ofast_mn
	gcc -Wall -Werror -Wextra HireMe_Base.c -Ofast -march=native -o build/HireMe_Base_Ofast_mn

HireMe_Base_O3_mn: clean_HireMe_Base_O3_mn
	gcc -Wall -Werror -Wextra HireMe_Base.c -O3 -march=native -o build/HireMe_Base_O3_mn

HireMe_Base_mn: clean_HireMe_Base_mn
	gcc -Wall -Werror -Wextra HireMe_Base.c -march=native -o build/HireMe_Base_mn

clean_HireMe_Ofast:
	rm build/HireMe_Ofast || true

clean_HireMe_O3:
	rm build/HireMe_O3 || true

clean_HireMe:
	rm build/HireMe || true

clean_HireMe_Base_Ofast:
	rm build/HireMe_Base_Ofast || true

clean_HireMe_Base_O3:
	rm build/HireMe_Base_O3 || true

clean_HireMe_Base:
	rm build/HireMe_Base || true

clean_HireMe_Ofast_mn:
	rm build/HireMe_Ofast_mn || true

clean_HireMe_O3_mn:
	rm build/HireMe_O3_mn || true

clean_HireMe_mn:
	rm build/HireMe_mn || true

clean_HireMe_Base_Ofast_mn:
	rm build/HireMe_Base_Ofast || true

clean_HireMe_Base_O3_mn:
	rm build/HireMe_Base_O3_mn || true

clean_HireMe_Base_mn:
	rm build/HireMe_Base_mn || true

clean: clean_HireMe_Ofast clean_HireMe_O3 clean_HireMe clean_HireMe_Base_Ofast clean_HireMe_Base_O3 clean_HireMe_Base clean_HireMe_Ofast_mn clean_HireMe_O3_mn clean_HireMe_mn clean_HireMe_Base_Ofast_mn clean_HireMe_Base_O3_mn clean_HireMe_Base_mn