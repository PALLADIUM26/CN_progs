#include<stdio.h>
#include<stdlib.h>
void main()
{
int a[10],b[10],c[20], temp, sum [10], sum1 [10],chk[10], carry=0,n,i,p, chkr [20], chks [ 20];

printf("------ -Checksum program for two segments only \n\r");
printf("\n Enter the number of bits of each segment..");
scanf("%d",&n);
printf("\n At the sender's end....");
printf("\n\r--------------------------------------\n\r");
printf("\n\r Enter the first segment(%d bits one after another): ",n);
for(i=n-1;i>=0;i--)
{
scanf("%d",&a[i]);
}
printf("\n\r Enter the second segment "); 
for(i=n-1;i>=0;i--);
{
scanf("%d",&b[i]);
}
for(i=0; i<n; i++)
{
sum[i]=(a[i]+b[i]+carry)%2; 
carry=(a[i]+b[i]+carry)/2;
}
printf("\n sum ...."); 
for(i=n-1;i>=0;i--)
printf("%d", sum[i]);

if(carry==1)
{
for(i=0;i<n;i++) 
{
 p=(sum[i]+carry)%2; 
 carry=(sum[i]+carry)/2; 
 sum[i]=p; 
 }
}
printf("\n Wrappedsum ....");
for(i=n-1;i>=0;i--)
{
chk[i]=sum[i];
printf("%d", sum[i]);
}

printf("\n Checksum....."); 
for(i=n-1;i>=0;i--)
{
if(chk[i]==1)
chks[i]=0;
else chks[i]=1;
printf("%d", chks[i]);
}
printf("\n\r At the RECEIVER's end....");
carry=0;
printf("\n\r Enter the received bits one after another: \n\r"); 
for(i=n-1;i>=0;i--)
{
scanf("%d",&a[i]);
} 
printf("\n\rNext bits will be identified as checksum\n\r"); 
for(i=n-1;i>=0;i--)
{ 
sum1[i]=(a[i]+b[i]+c[i]+carry)%2; 
carry=(a[i]+b[i]+c[i]+carry)/2;
}
printf("\n sum ...."); 
for(i=n-1;i>=0;i--)
printf("%d", sum1[i]);

if(carry==1)
{ 
for(i=0;i<n;i++)
{ 
p=(sum1[i]+carry)%2; 
carry=(sum1[i]+carry)/2; 
sum1[i]=p;
}
}
printf("\n Wrapped sum ...."); 
for(i=n-1;i>=0;i--)
{
chkr[i]=sum1[i];
printf("%d", sum1[i]); 
}
printf("\n Checksum....."); 
temp=0;
for(i=n-1;i>=0;i--)
{
if(chkr[i]==1)
chkr[i]=0;
else chkr[i]=1;
temp=temp+chkr[i];
printf("%d", chkr[i]);
}
if(temp!=0)
{
printf("\n\r Checksum FAILED, Received data is Corrupted.");
}
else
{
printf("\n\r Checksum PASSED.");
}
}
