int power_function(int n, int j)
{
    if (n == 0)
    {
        return 0;
    }
    if (j == 1)
    {
        return n;
    }
    else
    {
        if (j % 2 == 0)
            return power_function(n * n, j / 2);
        else
        {
            return n * power_function(n * n, (j - 1) / 2);
        }
    }
}