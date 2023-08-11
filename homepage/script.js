document.addEventListener("DOMContentLoaded", function(){
    let elem = document.getElementById("nav");
    let buttons = elem.children;

    for(button of buttons){
        button.addEventListener("click", function (){
            let name = event.target.firstChild.href;
            location.name = name;
        });
    }

});

//        <script src="script.js"></script>
//<button class="col-lg-4 col-md-4 col-sm-4 btn"></button>