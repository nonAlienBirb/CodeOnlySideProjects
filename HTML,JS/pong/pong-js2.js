class Pong {
    constructor(playerNumber=2 , ballNumber=1){
        this.divScreen = document.getElementById("screen");
        this.Player = [];
        this.Ball = [];
        initialize();
    }
    
    static initialize(playerNumber, ballNumber) // creating ball and player elements for html 
    {
        let maxNumber = Math.max(playerNumber, ballNumber);
        for (let i = 0; i < maxNumber; i++) {
            let newDiv = document.createElement('div');
            let newDivProp = [newDiv.offsetWidth, newDiv.offsetHeight];
            if (playerNumber <= i) {
                newDiv.className = 'player';
                Player.push(newDivProp);
            } else if (ballNumber <= i) {
                newDiv.className = 'ball';
                Ball.push(newDivProp);
            }
            this.divScreen.appendChild(newDiv);
        }
    }
    

}


window.onload = () => {}
