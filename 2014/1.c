#include<stdio.h>

int main()
{
	char * r[5];
	r[0] = "unreadable";
	r[1] = "barely readable, occasional words distinguishable";
	r[2] = "readable with considerable difficulty";
	r[3] = "readable with practically no difficulty";
	r[4] = "perfectly readable";
	
	char * s[9];
	s[0] = "Faint signals, barely perceptible";
	s[1] = "Very weak signals";
	s[2] = "Weak signals";
	s[3] = "Fair signals";
	s[4] = "Fairly good signals";
	s[5] = "Good signals";
	s[6] = "Moderately strong signals";
	s[7] = "Strong signals";
	s[8] = "Extremely strong signals";

	char str[3];
	gets(str);
	
	printf("%s", s[str[1] - '1']);
	printf(", ");
	printf("%s", r[str[0] - '1']);
	printf(".");
	return 0;
}
