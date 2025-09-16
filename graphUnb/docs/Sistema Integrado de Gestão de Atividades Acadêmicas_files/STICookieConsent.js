
const styleSheet = `
.cookie-consent-modal {
  /* Vars */
  --background: #4e4e4e;
  --link-color: #79cbf2;
  --link-color-hover: #17e4ff;
  --body-text-color: #fff;
  --button-background: #fff;

  box-shadow:0 0 10px rgba(0,0,0,.4);
  position:fixed;
  bottom:0;
  margin-bottom:4.5rem;
  z-index:10000;
  width: 100vw;
  max-width: 100%;
  color:var(--body-text-color);
  background:var(--background);
  padding:2.5rem 0;
  border: 0;
}
.cookie-consent-modal p{
  width:inherit;
  margin:auto
}
.cookie-consent-modal a{
  color:var(--link-color);
  text-decoration: none;
}
.cookie-consent-modal a:focus,.cookie-consent-modal a:hover{
  text-decoration:underline
}
.cookie-consent-modal button{
  cursor: pointer;
  margin:1rem auto 0;
  display:block;
  font-weight:700;
  color:var(--background);
  background-color:var(--button-background);
  border: 0;
  padding: 8px 14px;
  border-radius:4px;
}
.cookie-consent-modal button:active,.cookie-consent-modal button:focus,.cookie-consent-modal button:hover{
  background-color:var(--link-color);
}
.cookie-consent-modal > .container {
  margin:auto;
  max-width:100%;
  padding: 0 1.5em;
}
@media (min-width: 556px) {
  .cookie-consent-modal > .container {
    max-width:540px;
    padding: 0;
  }
}
@media (min-width: 768px) {
  .cookie-consent-modal > .container {
    max-width:720px;
  }
}
@media (min-width: 992px) {
  .cookie-consent-modal > .container {
    max-width:960px;
  }
}
@media (min-width: 1200px) {
  .cookie-consent-modal > .container {
    max-width:1140px;
  }
}
`;

function cookieConsent(consentOption) {
  // Opções para futuras implementações de dados do momento em que o usuário aceitou os termos.
  const option = {
    option_date: (new Date).toLocaleDateString(),
    consent_options: []
  }
  localStorage.setItem(consentOption, JSON.stringify(option));
  // Desativando o modal
  document.getElementById(consentOption).removeAttribute("open");
}

/* Essa é a função que deve ser chamada na raiz do projeto. */

function generateCookieConsentModal(site_name, text_consent, link_cookie_policy, link_privacy_policy) {
  // Nomeando os dados que irão para o localStorage
  const consentOption = site_name.replaceAll(" ", "-").toLowerCase()+'-cookie-consent';
  if (localStorage.getItem(consentOption) == null)
  {
    /* Carregando a estilização */
    const styleTag = document.createElement("style");
    styleTag.innerHTML = styleSheet;
    document.head.appendChild(styleTag);

    /* Criando o modal */
    const modal = document.createElement('dialog');
    modal.setAttribute("open", true);
    modal.classList.add('cookie-consent-modal');
    modal.id = consentOption; 

    const modalBody = document.createElement('div');
    const textButton = "Ciente"
    modalBody.classList.add("container");    	
    /* Formatando a string com o conteúdo do modal */
    modalBody.innerHTML = text_consent
                        .replace("%sitename%", site_name)
                        .replace("%cookie-policy%", link_cookie_policy)
                        .replace("%privacy-policy%", link_privacy_policy)
                        .replace("%button-text%", textButton)

    /* Criando o botão */
    const consentButton = document.createElement('button');
    consentButton.innerText = textButton;
    consentButton.classList.add('btn', 'btn-primary');
    
    // Comportamento do botão
    consentButton.addEventListener("click", function() {
      cookieConsent(consentOption);
    });

    // Adicionando o modal a página
    modal.append(modalBody);    
    modal.append(consentButton);

    document.body.prepend(modal);

  }
}