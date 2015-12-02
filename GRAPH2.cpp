#include <stdio.h>
#include <stdlib.h>
class Clika
{
public:
	int **A, *comp, *can, *nott,n;
	Clika()
	{
		FILE *f = fopen("input.txt", "r");
		fscanf(f, "%d", &this->n);
		comp = (int*)malloc(sizeof(int)*n);
		can = (int*)malloc(sizeof(int)*n);
		nott = (int*)malloc(sizeof(int)*n);
		A = (int**)calloc(sizeof(int*), n);
		for (int i = 0; i < n; i++) {
			A[i] = (int*)calloc(sizeof(int), n);
			comp[i] = -1;
			can[i] = i;
			nott[i] = -1;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				fscanf(f, "%d", &A[i][j]);
	}
	void write()
	{
		for (int i = 0; i < n; i++) {
			printf("\n");
			for (int j = 0; j < n; j++)
				printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	bool empty(int *cand)
	{
		for (int i = 0; i < n; i++)
		{
			if (cand[i] != -1)
				return false;
		}
		return true;
	}
	void writecol(int *arr)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	int *novyi()
	{
		int *arr = (int*)malloc(sizeof(int)*n);
		for (int i = 0; i < n; i++)
			arr[i] = -1;
		return arr;
	}
	void extends(int *com,int *cand, int *nt)
	{
		if ((empty(cand) && empty(nt)))
		{
			for (int i = 0; i < n; i++)
				if (com[i] != -1)
					printf("%d ", com[i]);
			printf("\n");
		}
		else
		{
			//writecol(com); writecol(cand); writecol(nt);
			//printf("\n");
			for (int i = 0; i < n; i++)
				if (cand[i] != -1)
				{
					int * new_com = novyi();
					for (int j = 0; j < n; j++)
						if (com[j] != -1)
							new_com[j] = j;
					new_com[i] = i;
					int *new_cand = novyi();
					for (int j = 0; j < n; j++)
						if (cand[j] != -1)
							if (j != i)
								if (A[j][i] != 0)
									new_cand[j] = j;
					int * new_nt = novyi();
					for (int j = 0; j < n; j++)
						if (nt[j] != -1)
							if (j != i)
								if (A[j][i] != 0)
									new_nt[j] = j;
					extends(new_com, new_cand, new_nt);
					cand[i] = -1;
					nt[i] = i;
				}
		}
	}
};
void main()
{
	Clika *click = new Clika();
	click->write();
	click->extends(click->comp, click->can, click->nott);
}