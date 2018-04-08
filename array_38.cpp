/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/
 int max_path_sum(int A[], int B[], int l1, int l2)
{
//Your code here
    int i=0;
    int j=0;
    int sum1=0;
    int sum2=0;
    int result=0;
    while(i<l1&&j<l2)
    {
        if(A[i]>B[j])
        {
            sum2+=B[j++];
        }
        else if(A[i]<B[j])
        {
            sum1+=A[i++];
        }
        else
        {
            result+=max(sum1,sum2);
            sum1=0;
            sum2=0;
            while(i<l1&&j<l2&&A[i]==B[j])
            {
                result+=A[i++];
                j++;
            }
        }
    }
    while(i<l1)
    {
        sum1+=A[i++];
    }
    while(j<l2)
    {
        sum2+=B[j++];
    }
    result+=max(sum1,sum2);
    return result;
}
