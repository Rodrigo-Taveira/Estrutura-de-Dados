
primo(2).
primo(X):- X>2, sem_divisores(2,X).

sem_divisores(X,X).
sem_divisores(A,X) :- X mod A =\= 0,
			Aprox is A+1,
			sem_divisores(Aprox,X).
