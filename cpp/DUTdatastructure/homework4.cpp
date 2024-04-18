5 6 6
1 1 4
2 1 5
2 3 3
2 6 8
4 4 7
5 1 2

Loc(a_{ij})=Loc(a_{00})+5i-2+j-(i-2)
Loc(a_{ij})= Loc(a_{11})+5*(i-1)+j-i


Loc(a_{ij})=Loc(a_{11})+(((i<j?j:i)-1)*(i<j?j:i)/2+(i<j?i:j)-1)*L
Loc(a_{ij})=Loc(a_{11})+(((i>j?i:j)-1)*(i>j?i:j)/2+(i>j?j:i)-1)*L