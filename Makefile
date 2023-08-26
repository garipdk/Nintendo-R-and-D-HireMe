
all: HireMe_make HireMe_make_mn HireMe_make_Ofast HireMe_make_O3 HireMe_make_Ofast_mn HireMe_make_O3_mn HireMe_make_omp HireMe_make_mn_omp HireMe_make_Ofast_omp HireMe_make_O3_omp HireMe_make_Ofast_mn_omp HireMe_make_O3_mn_omp HireMe_make_Base HireMe_make_Base_mn HireMe_make_Base_Ofast HireMe_make_Base_O3 HireMe_make_Base_Ofast_mn HireMe_make_Base_O3_mn

HireMe_make: clean_HireMe_make
	gcc -Wall -Werror -Wextra -Wno-unknown-pragmas HireMe.c -lm -o build/HireMe_make

HireMe_make_mn: clean_HireMe_make_mn
	gcc -Wall -Werror -Wextra -Wno-unknown-pragmas HireMe.c -march=native -lm -o build/HireMe_make_mn

HireMe_make_Ofast: clean_HireMe_make_Ofast
	gcc -Wall -Werror -Wextra HireMe.c -Ofast -lm -o build/HireMe_make_Ofast

HireMe_make_O3: clean_HireMe_make_O3
	gcc -Wall -Werror -Wextra -Wno-unknown-pragmas HireMe.c -O3 -lm -o build/HireMe_make_O3

HireMe_make_Ofast_mn: clean_HireMe_make_Ofast_mn
	gcc -Wall -Werror -Wextra -Wno-unknown-pragmas HireMe.c -Ofast -march=native -lm -o build/HireMe_make_Ofast_mn

HireMe_make_O3_mn: clean_HireMe_make_O3_mn
	gcc -Wall -Werror -Wextra -Wno-unknown-pragmas HireMe.c -O3 -march=native -lm -o build/HireMe_make_O3_mn

HireMe_make_omp: clean_HireMe_omp
	gcc -Wall -Werror -Wextra HireMe.c -fopenmp -lm -o build/HireMe_omp

HireMe_make_mn_omp: clean_HireMe_make_mn_omp
	gcc -Wall -Werror -Wextra HireMe.c -march=native -fopenmp -lm -o build/HireMe_make_mn_omp

HireMe_make_Ofast_omp: clean_HireMe_make_Ofast_omp
	gcc -Wall -Werror -Wextra HireMe.c -Ofast -fopenmp -lm -o build/HireMe_make_Ofast_omp

HireMe_make_O3_omp: clean_HireMe_make_O3_omp
	gcc -Wall -Werror -Wextra HireMe.c -O3 -fopenmp -lm -o build/HireMe_make_O3_omp

HireMe_make_Ofast_mn_omp: clean_HireMe_make_Ofast_mn_omp
	gcc -Wall -Werror -Wextra HireMe.c -Ofast -march=native -fopenmp -lm -o build/HireMe_make_Ofast_mn_omp

HireMe_make_O3_mn_omp: clean_HireMe_make_O3_mn_omp
	gcc -Wall -Werror -Wextra HireMe.c -O3 -march=native -fopenmp -lm -o build/HireMe_make_O3_mn_omp




HireMe_make_Base: clean_HireMe_make_Base
	gcc -Wall -Werror -Wextra HireMe_make_Base.c -o build/HireMe_make_Base

HireMe_make_Base_mn: clean_HireMe_make_Base_mn
	gcc -Wall -Werror -Wextra HireMe_make_Base.c -march=native -o build/HireMe_make_Base_mn

HireMe_make_Base_Ofast: clean_HireMe_make_Base_Ofast
	gcc -Wall -Werror -Wextra HireMe_make_Base.c -Ofast -o build/HireMe_make_Base_Ofast

HireMe_make_Base_O3: clean_HireMe_make_Base_O3
	gcc -Wall -Werror -Wextra HireMe_make_Base.c -O3 -o build/HireMe_make_Base_O3

HireMe_make_Base_Ofast_mn: clean_HireMe_make_Base_Ofast_mn
	gcc -Wall -Werror -Wextra HireMe_make_Base.c -Ofast -march=native -o build/HireMe_make_Base_Ofast_mn

HireMe_make_Base_O3_mn: clean_HireMe_make_Base_O3_mn
	gcc -Wall -Werror -Wextra HireMe_make_Base.c -O3 -march=native -o build/HireMe_make_Base_O3_mn



clean_HireMe_make:
	rm build/HireMe_make || true

clean_HireMe_make_mn:
	rm build/HireMe_make_mn || true

clean_HireMe_make_Ofast:
	rm build/HireMe_make_Ofast || true

clean_HireMe_make_O3:
	rm build/HireMe_make_O3 || true

clean_HireMe_make_Ofast_mn:
	rm build/HireMe_make_Ofast_mn || true

clean_HireMe_make_O3_mn:
	rm build/HireMe_make_O3_mn || true

clean_HireMe_make_omp:
	rm build/HireMe_make_omp || true

clean_HireMe_make_mn_omp:
	rm build/HireMe_make_mn_omp || true

clean_HireMe_make_Ofast_omp:
	rm build/HireMe_make_Ofast_omp || true

clean_HireMe_make_O3_omp:
	rm build/HireMe_make_O3_omp || true

clean_HireMe_make_Ofast_mn_omp:
	rm build/HireMe_make_Ofast_mn_omp || true

clean_HireMe_make_O3_mn_omp:
	rm build/HireMe_make_O3_mn_omp || true


clean_HireMe_make_Base:
	rm build/HireMe_make_Base || true

clean_HireMe_make_Base_mn:
	rm build/HireMe_make_Base_mn || true

clean_HireMe_make_Base_Ofast:
	rm build/HireMe_make_Base_Ofast || true

clean_HireMe_make_Base_O3:
	rm build/HireMe_make_Base_O3 || true

clean_HireMe_make_Base_Ofast_mn:
	rm build/HireMe_make_Base_Ofast || true

clean_HireMe_make_Base_O3_mn:
	rm build/HireMe_make_Base_O3_mn || true

clean: clean_HireMe_make clean_HireMe_make_mn clean_HireMe_make_Ofast clean_HireMe_make_O3 clean_HireMe_make_Ofast_mn clean_HireMe_make_O3_mn clean_HireMe_make_omp clean_HireMe_make_mn_omp clean_HireMe_make_Ofast_omp clean_HireMe_make_O3 _ompclean_HireMe_make_Ofast_mn_omp clean_HireMe_make_O3_mn_omp clean_HireMe_make_Base clean_HireMe_make_Base_mn clean_HireMe_make_Base_Ofast clean_HireMe_make_Base_O3 clean_HireMe_make_Base_Ofast_mn clean_HireMe_make_Base_O3_mn