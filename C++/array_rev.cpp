# include<iostream>
using namespace std;


void merge(int array[] , int l , int mid , int r)
{
    int n1 = mid -l +1 ;
    int n2 = r - mid ;

    int arr1[n1] , arr2[n2];
    for (int i = 0 ; i<n1 ; i++)
    {
        arr1[i] = array[l+i];
    }
    for (int i = 0 ; i<n2 ; i++)
    {
        arr2[i] = array[mid+i+1];
    }

    int i = 0 ;
    int j = 0 ;
    int k = l ;

    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            array[k] = arr1[i];
            k++ ; i++ ;
        }
        else 
        {
            array[k] = arr2[j];
            k++ ; j++ ;
        }
    }
    while(i<n1)
    {
        array[k] = arr1[i];
            k++ , i++ ;
    }
    while(j<n2)
    {
        array[k] = arr2[j];
            k++ , j++ ;
    }
 }



void Merge_sort(int array[] , int start , int end)
{
    if(start< end)
    {
        int mid = (start + end)/2 ;
        Merge_sort(array , start, mid);
        Merge_sort(array , mid+1, end );
        merge(array , start , mid, end);
    }

}

void printarray(int array[] , int size)
{
    for(int i = 0 ; i<size ; i++)
    {
        cout<< array[i]<<"  ";
    }
    cout<<endl;
}


int main()
{
    int arr[] = { 9 ,85 , -20 , 22,1, 19,3 ,-4 ,67,32 ,-2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printarray(arr , n);
    Merge_sort(arr ,0 ,  n-1);
    printarray(arr , n);


}