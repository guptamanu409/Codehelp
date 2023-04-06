
let change = document.querySelector('.change');

function inc(){
    let value = change.textContent;
    let numeric = parseInt(value);
    numeric++;
    change.textContent = numeric;
}

function dec(){
    let value = change.textContent;
    let numeric = parseInt(value);
    numeric--;
    change.textContent = numeric;
}
