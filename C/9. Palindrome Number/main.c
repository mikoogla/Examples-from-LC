bool isPalindrome(int x){
    if(x<0) return false;
    unsigned int reverse = 0;
    unsigned short int rem;
    int copy = x;
    while (x!=0){
        rem = x%10;
        reverse = reverse * 10 + rem;
        x /= 10;
    }
    if(copy == reverse)  return true;
    return false;
}