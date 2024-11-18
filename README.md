
This algorithm calculates a coefficient that modifies every year and 
represents what percent of railroad is broken. Each route represents 
a railroad and it is composed from more segments. Each segment has a 
coefficient. The coefficient will modify every year by these rules:

- if the coefficient is diferent from zero, then i double that value

- if the coefficient is equal to zero, then i will take the biggest neighbour
(if there are other routes from that city the first segment, in that array
will be neighbour to the coefficient)

For this algorithm i implemented four structures: one for the list,
one for the index of the cities, one for the graph and one for the routes.
The function that calculates the coefficient is gradesOfSections(Graph g, int years).

First, i calculate the maximum of each list. After that, i take list by list
(i jumped over the list that are empty). I go through every node in the list and
i check every element of the array of segments. If the value in the array are
different from zero, then i double that value. If the value is equal to zero, then 
i take case by case.

The first case will be when the element is inside the array. In this case,
i will see which neighbour is bigger. At the end, the element will be
the maximum (of the two neighbours) divided by 2.

The second case will be when the size of the array is equal to one.
The element will be the maximum number (from the first position) from the 
other arrays divided by 2.

The third case will be when the element is the first in the array.
In this case, i will verify which number is bigger (the maximum from the
list or the second element in the array). In the end, the element will be
equal to the maximum divided by 2.

The fourth case will be when the element is the last in the array.
In this case, i will take which number is greater (he maximum from the
list or the neighbour inside the array). The element will be equal to 
the maximum between this two numbers divided by 2.






