document.addEventListener("DOMContentLoaded", function(){
    let elem = document.getElementById("nav");
    let buttons = elem.children;

    for(button of buttons){
        button.addEventListener("click", function (){
            let anchor_id = event.target.firstChild.id;
            console.log(anchor_id)
            var url = location.href;
            console.log(url);              //Saving URL without hash.
            location.href = "#"+anchor_id;                 //Navigate to the target element.
            history.replaceState(null,null,url);
        });
    }
    console.log(buttons);
});