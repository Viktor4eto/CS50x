document.addEventListener("DOMContentLoaded", function(){
    let elem = document.getElementById("nav");
    let buttons = elem.children;

    for(button of buttons){
        button.addEventListener("click", function (){
            let button_id = event.target.firstChild.id;
            var get = document.getElementById(button_id);
            console.log(get);
        });
    }
    console.log(buttons);
});