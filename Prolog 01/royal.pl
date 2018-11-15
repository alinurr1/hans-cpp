
father(X,Y) :- parent( X,Y ), male(X).
mother(X,Y) :- parent( X,Y ), female(X).

grandmother( X, Z ) :- mother( X, Y ), parent( Y, Z ).
grandfather( X, Z ) :- father( X, Y ), parent( Y, Z ).

grandchild( X, Z ) :- parent(X,Y), parent(Y,Z).
grandson( X, Y ) :- grandchild(X,Y), male(X).
granddaughter(X,Y) :- grandchild(X,Y), female(X).

sibling(Y1,Y2) :- parent(X1,Y1), parent(X2,Y1), male(X1),
                  parent(X1,Y2), parent(X2,Y2), female(X2),
                  X1 \= X2,
                  Y1 \= Y2.

sister(X,Y) :- female(X), sibling(X,Y).
brother(X,Y) :- male(X), sibling(X,Y).

parent( elizabeth, charles ).
parent( elizabeth, anne ).
parent( elizabeth, andrew ).
parent( elizabeth, edward ).

parent( philip, charles ).
parent( philip, anne ).
parent( philip, andrew ).
parent( philip, edward ).

parent( diana, william ).
parent( diana, harry ).

parent( charles, william ).
parent( charles, harry ).

parent( andrew, beatrice ).
parent( andrew, eugenie ).
parent( sarah, beatrice ).
parent( sarah, eugenie ).

parent( edward, louise ).
parent( edward, james ).
parent( sophie, louise ).
parent( sophie, james ).

female( elizabeth ).
female( anne ).
female( diana ).
female( sarah ).
female( eugenie ).
female( beatrice ).
female( sophie ).
female( louise ).

male( philip ).
male( charles ).
male( andrew ).
male( edward ).
male( william ).
male( harry ).
male( james ).
