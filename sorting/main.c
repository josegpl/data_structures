#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _input_ {
    int elem;
    int original_pos;
} input;

int *insertion(input *vetor, int n);
int *selection(input *vetor, int n);
void Merge(input *A,input *L,int leftCount,input *R,int rightCount);
void MergeSort(input *A,int n);
void heapify(input a[],int n);
void heapsort(input a[],int n);
void adjust(input a[],int n);
void CountingSort(input *vetor, int n, int max);
void quicksort(input *A, int len);

int main()
{
    int n;
    printf("Bem vindo. Antes de selecionar qual metodo de ordenacao, informe quantos elementos tera o vetor para ordenacao:");
    scanf("%d", &n);

    input *vetor = malloc(n*(sizeof(input)));
    if(vetor==NULL) exit(1);

    int *novo, flag, i, max =-1;

    srand(time(NULL));

    printf("Como desejara preencher o vetor? \n\n [1] Aleatoriamente\n [2] Ordem Decrescente\n [3] Ordem Crescente\n");
    printf("Opcao desejada: ");
    scanf("%d", &flag);

    int k = 0;

    switch(flag) {
        case 1: for(i=0; i<n; i++) {
                vetor[i].elem = rand() % n;
                vetor[i].original_pos = i;

                    if (vetor[i].elem>max) max = vetor[i].elem;
                    }
                 break;

        case 2:
                for(i=n; i>0; i--) {
                    vetor[k].elem = i;
                    vetor[k].original_pos = k;

                    if (vetor[k].elem>max) max = vetor[k].elem;
                    k++;
                }
                break;

        case 3:  for(i=0; i<n; i++) {
                    vetor[i].elem = i;
                    vetor[i].original_pos - i;

                    if (vetor[i].elem>max) max = vetor[i].elem;
                }
                break;

    }

    printf("\nVetor antes da ordenacao: ");
    for(i=0; i<n; i++) {
        printf("%d ", vetor[i].elem);
    }

    flag = 0;

    int auxpivot = 0;
    while(1) {
        printf("\n\n\t MENU \n\n  [1] InsertionSort\n  [2] SelectionSort\n  [3] MergeSort\n  [4] HeapSort\n  [5] CountingSort\n  [6] QuickSort\n\n");
        printf("Qual a opcao desejada? ");
        scanf("%d", &flag);

        switch(flag) {
            case 1: novo = insertion(vetor, n);
                    break;
            case 2: novo = selection(vetor, n);
                    break;
            case 3: MergeSort(vetor, n);
                    break;
            case 4: heapsort(vetor, n);
                    break;
            case 5: CountingSort(vetor, n, max);
                    break;
            case 6: printf("\n\n Qual sera a posicao do pivo?\n [1] Primeira\n [2] Ultima\n [3] Mediana");
                    printf("\nOpcao: ");
                    scanf("%d", &auxpivot);

                    if(auxpivot==1) quicksort_R(vetor, n);
                    else if (auxpivot==2) quicksort_L(vetor, n);
                         else quicksort(vetor, n);

                    break;
        }
        break;
    }

    printf("\n\n");
    printf("Vetor apos a ordenacao: ");

    for(i=0; i<n; i++) {
    printf("%d ", vetor[i]);
    }

    return 0;
}

int *insertion(input *vetor, int n) {

int i, j, k;

    for(i=1; i<n; i++) {
        k = vetor[i].elem;
        j = i-1;
        while(j >= 0 && vetor[j].elem>k) {
               vetor[j+1].elem = vetor[j].elem;
               j=j-1;

            }
         vetor[j+1].elem = k;
        }

return vetor;

}

int *selection(input *vetor, int n) {

 int i, min, j, aux;

for ( i = 0 ; i < n-1 ; i++ ){
      min = i;
      for (j = i + 1; j < n; j++ ) {
         if ( vetor[min].elem > vetor[j].elem )
            min = j;
      }
      if ( min != i )
      {
         aux = vetor[i].elem;
         vetor[i].elem = vetor[min].elem;
         vetor[min].elem = aux;
      }
   }
return vetor;

}

void Merge(input *A,input *L,int leftCount,input *R,int rightCount) {

	int i,j,k;

	// i para marcar o indice da subarray esquerda
	// j para marcar o indice da subarray direita
	// k para marcar o indice da subarray que foi 'juntada'

	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {

		if(L[i].elem  < R[j].elem) A[k++].elem = L[i++].elem;
		else A[k++].elem = R[j++].elem;
	}

	while(i < leftCount) A[k++].elem = L[i++].elem;
	while(j < rightCount) A[k++].elem = R[j++].elem;

}


void MergeSort(input *A,int n) {

	int mid,i;
	input *L, *R;

	if(n < 2) return; // sempre que um vetor tiver menos que 2 elementos, nao sera feito nada

	mid = n/2;  // encontra o indice medio

	// criam-se as subarrays esquerda e direita (L e R)
	// subarray esquerda ira conter os elementos [0 - mid-1]
	// e os elementos mid - n-1 irao fazer parte da subarray direita

	L = (input*)malloc(mid*sizeof(input));

	R = (input*)malloc((n- mid)*sizeof(input));

	for(i = 0;i<mid;i++) L[i].elem = A[i].elem;

	for(i = mid;i<n;i++) R[i-mid].elem = A[i].elem;

	MergeSort(L,mid);  // ordena-se a subarray esquerda

	MergeSort(R,n-mid);  // ordena-se a subarray direita

	Merge(A,L,mid,R,n-mid);  // junta-se L e R a A como um vetor ja ordenado

        free(L);

        free(R);
}

void heapsort(input a[],int n) {
	int i,t;
	heapify(a,n);
	for (i=n-1;i>0;i--) {
		t = a[0].elem;
		a[0].elem = a[i].elem;
		a[i].elem = t;
		adjust(a,i);
	}
}
void heapify(input a[],int n) {
	int k,i,j,item;
	for (k=1;k<n;k++) {
		item = a[k].elem;
		i = k;
		j = (i-1)/2;
		while((i>0)&&(item>a[j].elem)) {
			a[i].elem = a[j].elem;
			i = j;
			j = (i-1)/2;
		}
		a[i].elem = item;
	}
}
void adjust(input a[],int n) {
	int i,j,item;
	j = 0;
	item = a[j].elem;
	i = 2*j+1;
	while(i<=n-1) {
		if(i+1 <= n-1)
		   if(a[i].elem <a[i+1].elem)
		    i++;
		if(item<a[i].elem) {
			a[j].elem = a[i].elem;
			j = i;
			i = 2*j+1;
		} else
		   break;
	}
	a[j].elem = item;
}

void quicksort(input *A, int len) {
  if (len < 2) return;
  int pivot = A[len/2].elem;  //definimos que o nosso pivo estara na posicao mediana da Array
  int i, j;

  /*divisao*/
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (A[i].elem < pivot) i++;
    while (A[j].elem > pivot) j--;

    if (i >= j) break;

    int temp = A[i].elem;
    A[i].elem     = A[j].elem;
    A[j].elem     = temp;
  }
 /* recursao */
  quicksort(A, i);
  quicksort(A + i, len - i);
}

void quicksort_L(input *A, int len) {
  if (len < 2) return;
  int pivot = A[0].elem;
  int i, j;
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (A[i].elem < pivot) i++;
    while (A[j].elem > pivot) j--;

    if (i >= j) break;

    int temp = A[i].elem;
    A[i].elem     = A[j].elem;
    A[j].elem     = temp;
  }

  quicksort(A, i);
  quicksort(A + i, len - i);
}

void quicksort_R(input *A, int len) {
  if (len < 2) return;
  int pivot = A[len].elem;
  int i, j;
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (A[i].elem < pivot) i++;
    while (A[j].elem > pivot) j--;

    if (i >= j) break;

    int temp = A[i].elem;
    A[i].elem     = A[j].elem;
    A[j].elem     = temp;
  }

  quicksort(A, i);
  quicksort(A + i, len - i);
}


void CountingSort(input *vetor, int n, int max) {
    int atual = 0;

    int *countvetor = calloc(max, sizeof(int)); //preenche o novo vetor com 0

    for(atual = 0; atual<n; atual++) {
        countvetor[vetor[atual].elem]++;
    }

    int num = 0;
    atual = 0;

    while(atual <= n) {
        while(countvetor[num]>0) {
            vetor[atual].elem = num;
            countvetor[num]--;
            atual++;
            if(atual>n) break;
        }
        num++;
    }
//free(countvetor);
}
