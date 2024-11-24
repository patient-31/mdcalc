all:
		gcc source/times_table_2.c source/danc.c -o ttables_2 -lm
		gcc source/itomd.c source/danc.c -o itomd -lm
		gcc source/factor_finder.c source/danc.c -o factor_finder -lm
		gcc source/16column.c -o 16column
		gcc source/times_table.c source/danc.c -o ttables	
		gcc source/search.c -o search -lm
		gcc source/8column.c -o 8column
		gcc source/search_fast.c source/danc.c -o search_fast

ttables_2: 
		gcc -Wextra source/times_table_2.c source/danc.c -o ttables_2 -lm


itomd: 
		gcc -Wextra source/itomd.c source/danc.c -o itomd -lm
	
factor_finder: 
		gcc -Wextra source/factor_finder.c source/danc.c -o factor_finder -lm
		

		
16column:
		gcc source/16column.c -o 16column

ttables: 
		gcc  source/times_table.c source/danc.c -o ttables	
		
search:
		gcc source/search.c -o search -lm

8column:
		gcc source/8column.c -o 8column

search_fast:
		gcc source/search_fast.c source/danc.c -o search_fast
