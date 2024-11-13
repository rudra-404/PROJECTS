//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% VARIABLES %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// a variable for maintaining plying turns where, "true" indicating the 1st players turn
let turn = true;

/*
    lets create a 2D array for wining conditions

    [0] [1] [2]
    [3] [4] [5]
    [6] [7] [8]
*/

let winningPatterns = [
    [0, 1, 2] ,
    [3, 4, 5] ,
    [6, 7, 8] ,
    [0, 3, 6] ,
    [1, 4, 7] ,
    [2, 5, 8] ,
    [0, 4, 8] ,
    [2, 4, 6]
];

// A counting cariable to ensure that the game is draw or not
let drawCount = 0;

// a variable for checking the draw based on counting
let isDraw = false;

// Accessing 'draw-msg' class for Hiding and Showing the content
let drawMsg = document.querySelector(".draw-msg");

// Accessing all the Game boxes for 'O' and 'X'
let boxes = document.querySelectorAll(".box");

// Accessing Buttons that are connected to the 'reset-btn' class
let RESET = document.querySelectorAll(".reset-btn");

// Accessing 'winning-msg' class for Hiding and Showing the content
let winningMsg = document.querySelector(".winning-msg");

// Accessing 'comment' class for Showing the player name who won the game
let playerName = document.querySelector(".comment");



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% RESET GAME %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// lets create a function for Restart The Game
const resetGame = () => {
    turn = true;                          // turn ------------------------ default
    winningMsg.classList.add("hide");     // winning messege ------------- default
    drawCount = 0;                        // draw count ------------------ default
    if(isDraw){
        drawMsg.classList.add("hide");    // draw messege ---------------- default
        isDraw = false;                   // draw check ------------------ default
    }
    for(let box of boxes){
        box.disabled = false;             // Game Box clicking ability --- default
        box.innerText = "";               // Game Box Content ------------ default
    }
};

// ACTIVATED the buttons 'Reset' , 'New Game' and 'Play Again'
RESET.forEach(button => {
    button.addEventListener("click", resetGame);
});



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% GAME FUNCTION %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// to make clickable each and every Game Box, using addEventListner() and forEach() function
boxes.forEach(box => {
    box.addEventListener("click", () => {
        if(turn){
            box.innerText = "O"; // 1st player
            turn = false;        // condition that its 2nd players turn now
        }else{
            box.innerText = "X"; // 2nd player
            turn = true;         // condition that its 1st players turn now
        }
        box.disabled = true;     // to avoid overwrite 'X' and 'O' for a box
        drawCount++;
        if(drawCount==9){
            isDraw = true;
            draw();
        }
        else checkWinner();      // to check winning conditions
    });
});



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% WINNER CHECK %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// travarsing what is the value ( X , O or empty ) for the each box and checking the winning conditions
const checkWinner = () => {
    for(let pattern of winningPatterns){
        let value1 = boxes[pattern[0]].innerText;
        let value2 = boxes[pattern[1]].innerText;
        let value3 = boxes[pattern[2]].innerText;

        // checking the boxes is empty or not
        if( (value1 != "") && (value2 != "") && (value3 != "")){

            // checking the values of value1, value2 and value3 are same or not
            if( (value1 === value2) && (value2 === value3) ){

                // passing the argument 'value1' to indicates who won the game
                winner(value1);
            }
        }
    }
};

/*
    To Understand checkWinner() In Details :
    
    what is 'pattern' ?

    const checkWinner = () => {
        for(let pattern of winningPatterns){
            console.log(pattern);
        }
    };

    what is 'pattern' array ?

    const checkWinner = () => {
        for(let pattern of winningPatterns){
            console.log(
                pattern[0],
                pattern[1],
                pattern[2]
            );
        }
    };

    what is 'boxes' array ?

    const checkWinner = () => {
        for(let pattern of winningPatterns){
            console.log(
                boxes[ pattern[0] ],
                boxes[ pattern[1] ],
                boxes[ pattern[2] ]
            );
        }
    };

    to get innerText from the 'boxes' array

    const checkWinner = () => {
        for(let pattern of winningPatterns){
            console.log(
                boxes[ pattern[0] ].innerText,
                boxes[ pattern[1] ].innerText,
                boxes[ pattern[2] ].innerText
            );
        }
    };

    putting those value to these variable value1, value2, value3, to check if they are same or not !
*/



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% WINNING WINDOW %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// to show the winng window
const winner = (player) => {
    winningMsg.classList.remove("hide");
    
    if(player === "O"){
        playerName.innerText = "Player 1 Wins The Game";
    }else{
        playerName.innerText = "Player 2 Wins The Game";
    }

    // disabling all the boxes after getting an winner
    for(box of boxes){
        box.disabled = true;
    }
};



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% DRAW WINDOW %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// to show the winng window
const draw = () => {
    drawMsg.classList.remove("hide");
};