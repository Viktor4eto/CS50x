document.addEventListener("DOMContentLoaded", function(){
    let elem = document.getElementById("nav");
    let buttons = elem.children;

    for(button of buttons){
        button.addEventListener("click", function (){
            let button_id = event.target.firstChild.id;
            let loc = location.href;
            location.href = '#' + button_id;
            //var get = document.getElementById(button_id);
            //console.log(get.location.href);
        });
    }
    console.log(buttons);
});