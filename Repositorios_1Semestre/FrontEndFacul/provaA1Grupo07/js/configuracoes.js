// Coordenadas fictícias para a Cidade Imaginária
const cidadeSiderurgica = [-15.7801, -47.9292]; // Latitude e longitude fictícias (Brasília como exemplo)

// Inicializa o mapa e define o ponto central e o nível de zoom
const map = L.map('map').setView(cidadeSiderurgica, 13); // 'map' é o ID do elemento HTML onde o mapa será renderizado

// Adiciona a camada base do mapa usando tiles do OpenStreetMap
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
  attribution: 'Mapa fictício com Leaflet & OpenStreetMap', // Texto de atribuição exibido no canto inferior do mapa
}).addTo(map); // Adiciona a camada ao mapa

// Cria um marcador no ponto definido
L.marker(cidadeSiderurgica) // Usa as mesmas coordenadas para posicionar o marcador
  .addTo(map) // Adiciona o marcador ao mapa
  .bindPopup('<b>Rua Sem Número</b><br>Centro da Cidade Siderúrgica.') // Define o conteúdo do popup que aparece ao clicar no marcador
  .openPopup(); // Abre o popup automaticamente ao carregar o mapa