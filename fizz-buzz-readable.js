for (let i = 0; i < 100;) {
    i++;
    let fizz = i % 3 ? '' : 'fizz';
    let buzz = i % 5 ? '' : 'buzz';
    let fizzbuzz = fizz + buzz;
    let result = fizzbuzz || i;
    console.log(result);
}
