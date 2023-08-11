document.addEventListener("DOMContentLoaded", function(){
    let elem = document.getElementById("nav");
    let buttons = elem.children;

    for(button of buttons){
        button.addEventListener("click", function (){
            location.href = event.target.href;
        });
    }

});

//        <script src="script.js"></script>
//<button class="col-lg-4 col-md-4 col-sm-4 btn"></button>