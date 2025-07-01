function palindrome(chaine){
    const res = chaine.toLowerCase().replace(/[^a-z0-9]/g, '');
    return res === res.split('').reverse().join('') ;
}