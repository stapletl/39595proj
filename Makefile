all: # compile & run
	g++ -std=c++17 *.cpp
	./a.out TestCases/11
	cat ParserOutput/0.pout
compile: 
	g++ -std=c++17 *.cpp
0: # run test case 0
	./a.out TestCases/0
	cat ParserOutput/0.pout
1: # run test case 1
	./a.out TestCases/1
	cat ParserOutput/1.pout
2: # run test case 2
	./a.out TestCases/2
	cat ParserOutput/2.pout
3: # run test case 3
	./a.out TestCases/3
	cat ParserOutput/3.pout
4: # run test case 4
	./a.out TestCases/4
	cat ParserOutput/4.pout
5: # run test case 5
	./a.out TestCases/5
	cat ParserOutput/5.pout
6: # run test case 6
	./a.out TestCases/6
	cat ParserOutput/6.pout
7: # run test case 7
	./a.out TestCases/7
	cat ParserOutput/7.pout
8: # run test case 8
	./a.out TestCases/8
	cat ParserOutput/8.pout
9: # run test case 9
	./a.out TestCases/9
	cat ParserOutput/9.pout
10: # run test case 10
	./a.out TestCases/10
	cat ParserOutput/10.pout
11: # run test case 11
	./a.out TestCases/11
	cat ParserOutput/11.pout
12: # run test case 12
	./a.out TestCases/12
	cat ParserOutput/12.pout
13: # run test case 13
	./a.out TestCases/13
	cat ParserOutput/13.pout
14: # run test case 14
	./a.out TestCases/14
	cat ParserOutput/14.pout
15: # run test case 15
	./a.out TestCases/15
	cat ParserOutput/15.pout
16: # run test case 16
	./a.out TestCases/16
	cat ParserOutput/16.pout
17: # run test case 17
	./a.out TestCases/17
	cat ParserOutput/17.pout
18: # run test case 18
	./a.out TestCases/18
	cat ParserOutput/18.pout
19: # run test case 19
	./a.out TestCases/19
	cat ParserOutput/19.pout
20: # run test case 20
	./a.out TestCases/20
	cat ParserOutput/20.pout
21: # run test case 21
	./a.out TestCases/21
	cat ParserOutput/21.pout
22: # run test case 22
	./a.out TestCases/22
	cat ParserOutput/22.pout
23: # run test case 23
	./a.out TestCases/23
	cat ParserOutput/23.pout
24: # run test case 24
	./a.out TestCases/24
	cat ParserOutput/24.pout
25: # run test case 25
	./a.out TestCases/25
	cat ParserOutput/25.pout
26: # run test case 26
	./a.out TestCases/26
	cat ParserOutput/26.pout
27: # run test case 27
	./a.out TestCases/27
	cat ParserOutput/27.pout

memory: # compile & run with valgrind
	g++ -std=c++17 *.cpp
	valgrind --log-file=vallog ./a.out TestCases/13

clean: # remove executable
	rm ./a.out