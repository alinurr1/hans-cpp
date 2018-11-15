fact(0,1).

fact( N, M ) :-
   N > 0, N1 is N - 1, fact(N1,M1), M = N * M1.
