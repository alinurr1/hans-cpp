/*1*/

product( _, [], [] ).

product( X, [ F | R ], [ pair(X,F) | L ] ) :- product( X, R, L ).

cartesian( [], _, []).

cartesian( [F | R], X, C3 ) :- cartesian(R, X, C1),
			       product(F, X, C2),
			       append(C1, C2, C3).

/*2*/

deepmember( F, [ F | _ ] ).

deepmember( F, [ _ | T ] ) :- deepmember( F, T ).

deepmember( F, [ H | _ ] ) :- deepmember( F, H ).

/*3*/

notcontains( _, [] ) :- !.

notcontains( F, [ H | T ] ) :- notcontains( F, T ), F \= H.

/*4*/

setinsertion( F, S, [F | S] ) :- notcontains( F, S ), ! .

setinsertion( _, S, S ).

/*5*/

graph1( [ [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 3, 4 ], [ 4, 1 ] ] ).

graph2( [ [ 1, 2 ], [ 2, 3 ], [ 2, 4 ], [ 3, 4 ],
	[ 4, 3 ], [ 3, 1 ], [ 4, 1 ] ] ).

graph3( [ [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 3, 2 ],
	[ 3, 4 ], [ 2, 4 ], [ 4, 6 ], [ 4, 5 ],
	[ 5, 6 ], [ 6, 5 ], [ 6, 7 ], [ 5, 7 ],
	[ 7, 1 ] ] ).

/*5.A*/

allvertices( [], _ ).

allvertices( [ [ F, S ] | T ], W ) :- allvertices( T, W1 ), setinsertion( S, W1, W2 ), setinsertion( F, W2, W ).

/*5.B*/

connected( S0, S1, [ [ S0, S1 ] | _ ] ).

connected( S0, S1, [ [ _, _ ] | R ] ) :- connected( S0, S1, R ).

/*5.C*/

path( _, L, 1, _ , [ L ], L) :- !.

path(G, Vb, N, Fb, [Vb | R], L) :- connected( Vb, Nx, G ), Nx \= Fb,
																	 N1 is N - 1, N \= 1,
																	 path( G, Nx, N1, [ Nx | Fb ], R, L ).

hamiltoniancircuit( G, C ) :- allvertices( G, Vert ),
			      Vert = [ V0 | _ ],
			      length( Vert, N ),
			      path( G, V0, N, [ V0 ], C, LastV ), connected( LastV, V0, G ).
