# ex00

## cautela ao usar o throw 

Considere uma função que retorne ponteiro para uma memória dinamica. Se essa
função lançar uma excessão, significa que ela não retornou. O caller/handler
não terá como dar delete na memória alocada pela função.