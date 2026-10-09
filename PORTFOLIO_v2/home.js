import lang from "Lang/TxtEng";
import "./style.css";

const home = () => {
    return(
        <div class="home">
            <h1>Portfolio</h1>

            <div class="logo">
                <img class="logo" src="_img/logo_temporaire.png" alt="Logo"/>
                <img src="_img/white.jpg" alt="" class="fondblanc"/>
            </div>

            <div class="tv">
                <img src="" alt="[tv with 'looking for job' on the screen image/gif]"/>
            </div>

            <div class="changelog">
                <h2>Changelog</h2>
                <p>Currently building the website! If you still see this message that means I'm not done (and get out, i dont want to ruin the surprise!)</p>
            </div>

            <div class="goals">
                <h2>Goals</h2>
                <p>Finish this website before Christmas 2025. Find a way to make my .jsx files work so I can switch this website's language from English to French and vice versa. Optimize this website (because there's too many pictures). Finish NEO The World Ends With You so I can play Silksong.</p>
            </div>

            <div class="updates">
                <h2>Updates</h2>
                <p>I got accepted at Uni!!! Party!!!</p>
            </div>

            <div class="warning">
                <h2>Warning</h2>
                <p> <strong>Content warning:</strong> some of my art might contain blood and gore, viewer discretion is advised.</p>
                <p>Website currently broken, please be mindful on your way in.</p>
            </div>

    </div>
    )
}

export default home;