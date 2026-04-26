const myButton = document.getElementById("myFirstButton");

class SoundButton extends HTMLElement {
    constructor() {
        super();
        this.innerHTML = "<div>" 
        + (this.hasAttribute("img") ? `<img src = ${this.getAttribute("img")}>` : "")
        + `<audio src="${this.getAttribute("sound")}"></audio>` + "</div>";

        this.div = this.querySelector("div");
        this.audio = this.querySelector("audio");
    }
    connectedCallback() {
        this.div.addEventListener("click", () => {
            this.audio.play();
        });
    };
}

class LinkButton extends HTMLElement {
    constructor() {
        super();
        this.innerHTML = "<div>" 
        + (this.hasAttribute("img") ? `<img src = ${this.getAttribute("img")}>` : "")
        + "</div>";
        this.div = this.querySelector("div");
    }
    
    connectedCallback() {
        this.div.addEventListener("click", () => {
            window.location.href = this.getAttribute("href");
        });
    };
}

customElements.define("sound-button", SoundButton);
customElements.define("link-button", LinkButton);