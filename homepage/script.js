document.addEventListener("DOMContentLoaded", function(){
    let elem = document.getElementById("nav");
    let buttons = elem.children;

    for(button of buttons){
        button.addEventListener("click", function (){
            console.log(event.target.firstChild.href);
        });
    }
    console.log(buttons);
});