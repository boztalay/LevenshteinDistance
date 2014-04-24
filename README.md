LevenshteinDistance
===================

A quick implementation of Levenshtein distance

```
> g++ levenshtein.cpp -o levenshtein
> ./levenshtein saturday sunday
Words: saturday, sunday
Table dimensions: 9 7

*	*	-	s	u	n	d	a	y
*	*	0	1	2	3	4	5	6
-	0	0	1	2	3	4	5	6
s	1	1	0	1	2	3	4	5
a	2	2	1	1	2	3	3	4
t	3	3	2	2	2	3	4	4
u	4	4	3	2	3	3	4	5
r	5	5	4	3	3	4	4	5
d	6	6	5	4	4	3	4	5
a	7	7	6	5	5	4	3	4
y	8	8	7	6	6	5	4	3

Distance: 3
```
