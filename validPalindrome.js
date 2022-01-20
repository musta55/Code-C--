/**
 * @param {string} s
 * @return {boolean}
 */
 var isPalindrome = function(s) {
    const regex=/[\W_]/g;
    const alphaNumericString=s.replace(regex,"").toLowerCase();
    // for(int i=0;i<alphaNumericString.length();i++){
    //     if(!(alphaNumericString[i]==alphaNumericString[alphaNumericString.length()-1-i])return false;
    // }
    //     return true;
    
    const myStack=[];
    for(let i=0;i<alphaNumericString.length;i++){
        myStack.push(alphaNumericString[i]);
    }
    
    //check if alphaNumericString and myStack is same
    let ispalindrome= true;
     for(let i=0;i<alphaNumericString.length;i++){
       if(alphaNumericString[i]!=myStack.pop()){
           ispalindrome=false;
       }
    }
    return ispalindrome;
};