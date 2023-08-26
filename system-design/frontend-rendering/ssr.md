# Introduction

Server-side rendering (SSR) refers to an application's ability to generate a web page on the server, rather than merely rendering it in the browser. Through SSR, the server delivers a fully rendered page to the client, and then the client's JavaScript bundle takes over to enable the SPA (Single Page Application) framework to function. With SSR, since the page is produced on the server and transmitted to the client, it allows for the utilization of dynamic data while maintaining excellent SEO performance.

## Advantages

- Suitable for creating pages with dynamic content.
    
- Although not as speedy as SSG (Static Site Generation), SSR provides a perception of fast performance, as visible content becomes promptly available upon page load.

- Works well with search engines, so people can find your page easily (Considered SEO-friendly).

## Tradeoffs

- SSR necessitates substantial computational power on the server, as each request is processed there.

- Maintaining security for SSR sites is more challenging due to the larger potential attack surface.

- Implementing effective caching requires intricate configurations.

## When to Use SSR?

SSR is recommended when you want pages with dynamic content and a strong presence on search engines. Keep in mind that it demands a robust server, and ensuring security might be more complex. Additionally, configuring caching settings can be intricate.