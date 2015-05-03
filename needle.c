// Needelmann-Wunsch algorithm of simple two-sequence alignment
// Actually still on development stage

#include <stdio.h>
#include <String.h>

int max(int a, int b, int c) {
	if (a>=b && a>=c) {
		return a;
	}
	if (b>=a && b>=c) {
		return b;
	}
	return c;
}


void needle(int n, int m, char str1[n], char str2[m], int g_pen, int mm_pen, int m_score) {
	
// Calculating the dynamic-programming matrix
	int i,j;
	int mat[n+1][m+1];
	char alseq1[n+m], alseq2[n+m];
	
	for (i=0;i<=n;i++) {
		mat[i][0] = -i;
	}
	for (i=1;i<=m;i++) {
		mat[0][i] = -i;
	}
	
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			if (str1[i-1]==str2[j-1]) {
				mat[i][j] = max(mat[i-1][j-1]+m_score, mat[i][j-1]-g_pen, mat[i-1][j]-g_pen);
			}
			else {
				mat[i][j] = max(mat[i-1][j-1]-mm_pen, mat[i][j-1]-g_pen, mat[i-1][j]-g_pen);
			}
		}
	}
	
// Building alignment
	i = n;
	j = m;
	int step_max;
	int count;
	char divider[] = "-";
	count = 0;

	while (i!=0 && j!=0){
		step_max = max(mat[i-1][j-1], mat[i][j-1], mat[i-1][j]);
		if (mat[i-1][j-1] == step_max) {
			alseq1[count] = str1[i-1];
			alseq2[count] = str2[j-1];
			i -= 1;
			j -= 1;
			count += 1;
		}
		else if (mat[i][j-1] == step_max) {
			alseq1[count] = divider[0];
			alseq2[count] = str2[j-1];
			j -= 1;
			count += 1;
		}
		else {
			alseq1[count] = str1[i-1];
			alseq2[count] = divider[0];
			i -= 1;
			count += 1;
		}
		if (i<0) {
			i = 0;
		}
		if (j<0) {
			j = 0;
		}
	}
	
// Printing aligmnent	
	printf("\n");
	for(i=count-1;i>=0;i--) {
		printf("%c", alseq1[i]);
	}
	printf("\n");
	for(j=count-1;j>=0;j--) {
		printf("%c", alseq2[j]);
	}
	printf("\n");
}


int main() {
	int gap_pnlt, mism_pnlt, mtch_rev, len1, len2;
	char seqfile1[30], seqfile2[30], str1[50000], str2[50000];
	
	printf("Gap penalty: ");      scanf("%d", &gap_pnlt);
	printf("Mismatch penalty: "); scanf("%d", &mism_pnlt);
	printf("Match reward: ");     scanf("%d", &mtch_rev);
	printf("Input 2 files containing plain sequences in one string\n");
	printf("First sequence: ");   scanf("%s", seqfile1);
	printf("Second sequence: ");  scanf("%s", seqfile2);
	
	FILE *seq1 = fopen(seqfile1, "r");
	FILE *seq2 = fopen(seqfile2, "r");
	fscanf(seq1, "%s", str1);
	fscanf(seq2, "%s", str2);
	
	len1 = strlen(str1);
	len2 = strlen(str2);
	
	needle(len1, len2, str1, str2, gap_pnlt, mism_pnlt, mtch_rev);
	return 0;
}
