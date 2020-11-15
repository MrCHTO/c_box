#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Bubble_Sort(int arr[], int length)
{
    int temp;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void Bubble_New_Sort(int arr[], int length)
{
    int temp, flag;
    for (int i = 0; i < length; i++)
    {
        flag = 1;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
}
void Insert_Sort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp;
        int j = i = 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
void Quick_Core(int arr[], int start, int end)
{
    int left, right, temp, mid;
    if (start > end)
    {
        return;
    }
    mid = arr[start];
    left = start;
    right = end;
    while (left != right)
    {
        while (arr[right] >= mid && left < right)
        {
            right--;
        }
        while (arr[left] <= mid && left < right)
        {
            left++;
        }
        if (arr[left] >= arr[right])
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    //left==right
    arr[start] = arr[left];
    arr[left] = mid;
    Quick_Core(arr, left, left - 1);
    Quick_Core(arr, left + 1, right);
}
void Quick_Sort(int arr[], int length)
{
    Quick_Core(arr, 0, length - 1);
}
void Hill_Sort(int arr[], int length)
{
    int h, j, k, t;
    for (h = length / 2; h > 0; h = h / 2)
    {
        //控制增量
        for (j = h; j < length; j++)
        {
            t = arr[j];
            for (k = j - h; k >= 0 && t < arr[k]; k -= h)
            {
                arr[k + h] = arr[k];
            }
            arr[k + h] = t;
        }
    }
}
void Select_Sort(int s[], int len)
{
    int i, j, min;
    for (i = 0; i < len - 1; i++)
    {
        min = i;
        for (j = i + 1; j < len; j++)
        {
            if (s[min] > s[j])
            {
                min = j; //把值最小的下标记下来
            }
        }
        if (min != i)
        {
            swap(s[i], s[min]);
        }
    }
}
int main()
{
}