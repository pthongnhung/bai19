#include<stdio.h>
struct sinhvien{
	int id;
	char name[50];
	int age;
	char phoneNumber[50];
}; 
void insinhvien(struct sinhvien sv){
	printf("id=%d, ten=%s, tuoi=%d, sdt=%s\n",sv.id,sv.name,sv.age,sv.phoneNumber);
}
void indanhsachsinhvien(struct sinhvien sv[], int currentlength){
	for(int i=0;i<currentlength;i++){
		insinhvien(sv[i]);
	}
}
void xoasinhvien(int idTodelete,struct sinhvien sv[], int *currentlength){
	int found=0; 
	for(int i=0;i<*currentlength;i++){
		if(sv[i].id==idTodelete){
			found=1; 
			for(int j=i;j<*currentlength-1;j++){
				sv[j]=sv[j+1];
					*currentlength--; 
			}
		}
	}
	if(found==0){
		printf("khong tim thay sinh vien co id %d\n",idTodelete);
	}
}
int main(){
    struct sinhvien sv[5]={
       {1,"pham thi hong nhung",18,"0348723718"},
       {2,"pham thi hong ",19,"03487237"},
       {3,"pham thi nhung",20,"034872371"},
       {4,"pham hong nhung",21,"0348723123"},
       {5,"pham nhung",22,"0348723712"}
    };  
    int currentlength=5;
    int idTodelete; 
	printf("danh sach sinh vien truoc khi xoa\n");
	indanhsachsinhvien(sv,currentlength);
	printf("moi ban nhap id cua sinh vien can xoa: ");
	scanf("%d",&idTodelete);
	xoasinhvien(idTodelete,sv,&currentlength);
	printf("danh sach sinh vien sau khi xoa\n");
	indanhsachsinhvien(sv,currentlength);
return  0;
}

