bool isHappy(int n) {
    int ans = 0, temp = n, count = 1000;
    while (count--) {
        while (temp) {
            ans += (temp % 10) * (temp % 10);
            temp /= 10;
        }
        temp = ans;
        ans = 0;
        if (temp == 1) return true;
    }
    return false;

}
//Âú·Ö´úÂë
bool isHappy(int n) {
    if(n<=0)
        return false;
    if(n<10)
    {
        if((n==1)||(n==7))
            return true;
        else return false;
    }
    else
        return isHappy(sum(n));
}
int square[10] = {0,1,4,9,16,25,36,49,64,81};
int sum(int n)
{
    int sum = 0;
    while(n!=0)
    {

        sum+= square[n%10];
        n = n/10;
    }
    return sum;
}
