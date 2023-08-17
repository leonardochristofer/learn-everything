# Introduction, what is HTTP in simple terms?

HTTP (Hypertext Transfer Protocol) is a protocol used for communication between web browsers (like Google Chrome, Mozilla Firefox) and web servers (where websites are hosted). It allows users to request and access web pages, images, videos, and other resources on the internet.

1. When you type a web address (URL) in your browser and hit Enter, your browser sends an HTTP request to the web server asking for the webpage or resource.
    
2. The web server receives the request, processes it, and sends back an HTTP response with the requested content.
    
3. Your browser then displays the webpage or resource you requested, and you can interact with it on your screen.

## HTTP/1, HTTP/1.1, HTTP/2, and HTTP/3:

HTTP has evolved over time, and different versions have been released. Here are the key differences, advantages, and tradeoffs between HTTP/1, HTTP/1.1, and HTTP/2:

## HTTP/1:
    
### Characteristics:

- Connection Per Request: HTTP/1 uses a separate connection for each request and response. After each request, the connection is closed, and a new one is established for the next request.

### Advantages:

- Simplicity: It's straightforward to implement and understand.

- Compatibility: It is widely supported by browsers and servers.

### Tradeoffs:

- Connection Overhead: Establishing a new connection for each request can lead to increased latency and slower page loading times, especially for websites with many resources.

## HTTP/1.1:

### Characteristics:

- Persistent Connections: HTTP/1.1 introduced persistent connections, allowing multiple requests and responses to be sent over the same connection, reducing the overhead of opening and closing connections.
    
- Chunked Transfer Encoding: It allows the server to send the response in smaller "chunks," making it possible for browsers to display the page progressively as chunks arrive.

### Advantages:

- Reduced Latency: Persistent connections and chunked transfer encoding improve page loading speed compared to HTTP/1.

- Hostname Multiplexing: **Multiple requests to the same server** can be sent over a single connection, reducing the number of connections needed.

### Tradeoffs:

- Requests on the same connection can get stuck behind a slow response, causing delays.

## HTTP/2:

### Characteristics:

- Binary Protocol: HTTP/2 uses a binary protocol instead of plain text, making it more efficient to parse and reducing the overhead of the protocol itself.

- Multiplexing: **HTTP/2 allowing multiple requests and responses** to be sent over the same connection simultaneously. This characteristic eliminates HTTP/1 tradeoffs.

- Server Push: Servers can **proactively send resources to the client's cache** before they are requested, reducing the need for additional requests.

- Stream Dependencies and Prioritization: HTTP/2 introduces stream dependencies and prioritization, allowing the server to indicate which streams are more important than others. While this improves efficiency, it can complicate debugging, especially when dealing with dependency and prioritization-related issues.

- Flow Control: HTTP/2 incorporates flow control mechanisms to prevent overwhelming clients with more data than they can handle. Properly handling flow control adds another layer of complexity to the implementation.

- TLS Encryption (Recommended): HTTP/2 is recommended to be used over TLS (HTTPS). While this provides security benefits, it also means that developers need to set up and manage TLS certificates, which can be a non-trivial task.

- Server-Side Configuration: Properly configuring the server to support HTTP/2 can be more involved than setting up traditional HTTP/1.x servers. Some server configurations may require additional tweaks to optimize performance and compatibility.

### Advantages:

- Faster Page Loading: Multiplexing and server push significantly improve page loading speed and performance.

- Reduced Latency: The binary protocol and other optimizations reduce latency further.
    
### Tradeoffs:

- Complexity: HTTP/2's binary protocol adds complexity, which might make debugging and implementation more challenging.
        
- Server Resource Usage: HTTP/2 may require more server resources due to increased multiplexing and parallelism.

Despite these challenges, HTTP/2's performance benefits, including multiplexing, server push, and reduced latency, make it a compelling choice for modern web applications. However, developers need to be aware of the potential complexities and ensure they have the necessary knowledge to debug and implement HTTP/2 effectively.

## HTTP/3:

### Characteristics:

- Major upgrade of HTTP. An important difference in HTTP/3 is that it runs on QUIC, a new transport protocol. QUIC is designed for mobile-heavy internet usage in which people carry smartphones that constantly switch from one network to another as they move about their day. This was not the case when the first Internet protocols were developed: devices were less portable and did not switch networks very often.

- The use of QUIC means that HTTP/3 relies on the User Datagram Protocol (UDP), not the Transmission Control Protocol (TCP). Switching to UDP will enable faster connections and faster user experience when browsing online. 

- The connection will always be encrypted. Previously, in HTTPS, the encryption and transport-layer connections occurred separately. TCP connections could carry data that was either encrypted or unencrypted, and the TCP handshake and TLS handshake were distinct events. However, QUIC sets up encrypted connections by default at the transport-layer —— application-layer data will always be encrypted.

- QUIC accomplishes this by combining the two handshakes into one action, reducing latency since applications must wait for only one handshake to finish before sending data. It also encrypts metadata about each connection, including packet numbers and some other parts of the header, to help keep information about user behavior out of attackers’ hands. This feature was not included in HTTP/2. Encrypting this data helps keep actionable information about user behavior out of attackers’ hands.

### Advantages:

- Developing a workaround for the sluggish performance when a smartphone switches from WiFi to cellular data (such as when leaving the house or office)

- Decreasing the effects of packet loss — when one packet of information does not make it to its destination, it will no longer block all streams of information (a problem known as “head-of-line blocking”)

- Faster connection establishment: QUIC allows TLS version negotiation to happen at the same time as the cryptographic and transport handshakes

- Zero round-trip time (0-RTT): For servers they have already connected to, clients can skip the handshake requirement (the process of acknowledging and verifying each other to determine how they will communicate)

- More comprehensive encryption: QUIC’s new approach to handshakes will provide encryption by default — a huge upgrade from HTTP/2 — and will help mitigate the risk of attacks

### Tradeoffs:

- Compatibility problems. Not all browsers, servers, and proxies support the new protocols, and some may even degrade or block them.

- Complexity, supporting more protocols means more resources and logic on the server side, as well as more code and libraries on the client side which increase the maintenance cost and the risk of bugs and vulnerabilities.

- Consistency. Depending on the protocol used, the web application may behave differently or deliver different results (e.g: HTTP/1, HTTP/1.1, HTTP/2, and HTTP/3 have a different ways of handling prioritization, flow control, and error recovery) which could affect the user experience and the web analytics.

## Conclusion:

In summary, HTTP is the protocol used for communication between web browsers and servers. Each version comes with its own set of tradeoffs, which must be considered when choosing the appropriate version for a specific use case. Compatibility, complexity, and consistency are the most important things to consider before implementing or choosing any protocols.