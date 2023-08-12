# Introduction

OSI model is a conceptual that defines networking or telecommunications systems as 7 layers.

# Why do we need to know the OSI model?

The layers are useful to visualize what is going on within their networks and it could help to narrow down problems:

- To know is it a physical issue or something wrong with the application?

- Make troubleshooting easier and help identify threats across the entire stack.

- Essential for developing a security-first mindset.

# Layer 7 - Application (e.g: HTTP/HTTPS/HTTP3)

The layer that directly perform data exchange between user and server. Software applications rely on the application layer to initiate communication. But, it does not mean that software applications is a part of the application layer, rather the application layer is responsible for the protocols and data manipulation to serve meaningful data (e.g: http response status, resource, etc) to the user.

# Layer 6 - Presentation (e.g: SSL/TLS)

The data from the application layer is extracted here and manipulated as per the required format to transmit over the network. The functions of the presentation layer are translation, encryption/decryption (e.g: data encryption/decryption for a secure transmission), and compression. 

# Layer 5 - Session

Session layer are responsible for opening and closing communication between the two devices which commonly known as session. The session layer ensures that the session stays open long enough to transfer all the data being exchanged (e.g: how long should a system wait for a response from the user), and then promptly closes the session (e.g: a termination between the applications at each end of the session) in order to avoid wasting resources.

# Layer 4 - Transport (e.g: TCP/UDP)

Transport layer are responsible for end-to-end communication between the two devices (e.g: How much data to send, at what rate, where it goes, etc), this includes taking data from the session layer and breaking it up into chunks called segments before sending it to the network layer (layer 3). It is also responsible for reassembling the segments on the receiving device into data the session layer can consume. 

The best known example of the transport layer is the Transmission Control Protocol (TCP), which is built on top of the Internet Protocol (IP), commonly known as TCP/IP. TCP and UDP port numbers work at layer 4, while IP addresses work at layer 3, the network layer.

# Layer 3 - Network

The network layer is responsible for facilitating data transfer between two different networks. The network layer breaks up segments from the transport layer into smaller units, called packets, on the sender's device, and reassembles these packets on the receiving device. The network layer also finds the best physical path for the data to reach its destination this is known as routing. If the two devices communicating are on the same network, then the network layer is unnecessary.

# Layer 2 - Data Link

The data link layer is very similar to the network layer, except the data link layer facilitates data transfer between two devices on the same network. The data link layer takes packets from the network layer and breaks them into smaller pieces called frames.

# Layer 1 - Physical

Physical layer represents the electrical and physical equipment involved in the data transfer, such as the cables and switches. When a networking issue occurs, the physical layer is gonna be the first one to be checked to ensure that all of the cables are properly connected and that the power plug hasn’t been pulled from the router, switch or computer.
