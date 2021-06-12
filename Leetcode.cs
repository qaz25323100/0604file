using System;

namespace CSharpLeetCode
{
    public class Leetcode
    {
        public void Rotate(int[,] matrix)
        {
            int rowsOrHeight = matrix.GetLength(0) - 1;
            int a = 1, b = 1, c = rowsOrHeight - 1, d = rowsOrHeight - 1;
            for (int i = rowsOrHeight; i > 1; i--)
            {

                int tmp = matrix[0, a];
                matrix[0, a++] = matrix[b, rowsOrHeight]; //[0,1] = [1,2]
                matrix[b++, rowsOrHeight] = matrix[rowsOrHeight, c]; //[1,2] = [2,1]
                matrix[rowsOrHeight, c--] = matrix[0, d]; //[2,1] = [2,0]
                matrix[0, d--] = tmp;
            }
            for (int i = 0; i <= rowsOrHeight; i++)
            {
                for (int j = 0; j <= rowsOrHeight; j++)
                {
                    Console.Write(matrix[i, j]);
                }
                Console.Write("\n");
            }
        }

        public long ArrangeCoins(int n)
        {
            for (long i = 2; i < n; i++)
            {
                if ((i + 1) * i / 2 > n) return i - 1;
            }
            return 0;
        }

        public void DuplicateZeros(int[] arr)
        {
            int length = arr.Length - 1;
            for (int i = 0; i < length; i++)
            {
                if (arr[i] == 0)
                {
                    for (int j = length; j > i; j--)
                    {
                        arr[j] = arr[j - 1];
                    }
                    i++;
                }
            }

            //for(int i=0;i<arr.Length;i++)Console.Write(arr[i]);

        }

        public void Merge(int[] nums1, int m, int[] nums2, int n)
        {
            int i=m-1;
            int j= n-1;
            int k= m+n-1;
            while(i>=0 && j >=0){
                nums1[k--] =  (nums1[i]>nums2[j])?nums1[i--]:nums2[j--];
            }
            while(j>=0){
                nums1[k--] = nums2[j--];
            }
            // for(int a=0;a<nums1.Length;a++)Console.Write(nums1[a]);
        }
    }
}
