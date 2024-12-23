#include<stdio.h>
#include<string.h> 
struct sinhvien{
	int id;
	char name[50];
	int age;
	char phoneNumber[50];
}; 
void insinhvien(struct sinhvien sv,int currentlength){
	printf("id=%d, ten=%s, tuoi=%d, sdt=%s\n",sv.id,sv.name,sv.age,sv.phoneNumber);
}
void indanhsachsinhvien(struct sinhvien sv[], int currentlength){
	for(int i=0;i<currentlength;i++){
		insinhvien(sv[i],currentlength);
	}
}
void sapxepsinhvien(struct sinhvien sv[],int currentlength){
	struct sinhvien temp;
	for(int i=0;i<currentlength-1;i++){
		for(int j=i+1;j<currentlength;j++){
			if(strcmp(sv[i].name,sv[j].name)>0){
				strcpy(temp.name,sv[i].name);
			    strcpy(sv[i].name,sv[j].name);
		    	strcpy(sv[j].name,temp.name);
			}
		}
	}
}
struct sinhvien sv[5]={
       {1,"pham thi hong nhung",18,"0348723718"},
       {2,"pham thi hong ",19,"03487237"},
       {3,"pham thi ",20,"034872371"},
       {4,"pham",21,"0348723123"},
       {5,"pham thi hong nhung haha",22,"0348723712"}
    };  
    int currentlength=5;
int main(){
    printf("danh sach sinh vien truoc khi duoc sap xep la\n");
    indanhsachsinhvien(sv,currentlength);
    sapxepsinhvien(sv,currentlength);
    printf("danh sach sinh vien sau khi duoc sap xep\n");
    indanhsachsinhvien(sv,currentlength);
return  0;
}

