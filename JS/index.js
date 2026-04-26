const myButton = document.getElementById("myFirstButton");

class SoundButton extends HTMLElement {
    result = "<div>";
    constructor() {
        super();
        if(this.hasAttribute("img")) {
            this.result+= `<img src = ${this.getAttribute("img")}>`;
        }
        this.result+=`<audio src="${this.getAttribute("sound")}"></audio>`
        this.innerHTML = this.result + "</div>";
        this.div = this.querySelector("div");
        this.audio = this.querySelector("audio");
    }
    connectedCallback() {
        this.div.addEventListener("click", () => {
            this.audio.play();
            console.log("Toto");
        });
    };
}
customElements.define("sound-bouton", SoundButton);
