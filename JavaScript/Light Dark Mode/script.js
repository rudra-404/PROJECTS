let body = document.querySelector("body");

let button = document.querySelector(".btn-light");

let footer = document.querySelector(".f-light");

let currentMODE = "light";

button.addEventListener("click",() => {
    if(currentMODE === "light"){
        body.setAttribute("class","dark");
        button.setAttribute("class","btn-dark");
        button.innerText = 'Light';
        footer.setAttribute("class","f-dark");
        currentMODE = "dark";
    }else{
        body.setAttribute("class","light");
        button.setAttribute("class","btn-light");
        button.innerText = 'Dark';
        footer.setAttribute("class","f-light");
        currentMODE = "light";
    }
    console.log(currentMODE);
});