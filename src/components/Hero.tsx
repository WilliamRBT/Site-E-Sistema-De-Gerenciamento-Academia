import React from 'react';

const Hero: React.FC = () => {
  return (
    <section 
      className="relative h-screen flex items-center justify-center text-center bg-cover bg-center"
      style={{ backgroundImage: "url('C:\Users\1Gp Pereiras\Downloads\dccaccce-94ad-4c92-aa1e-a199c7cafa64.png')" }}
    >
      <div className="absolute inset-0 bg-black/70"></div>
      <div className="relative z-10 px-4">
        <h2 className="text-5xl md:text-7xl font-black uppercase tracking-tighter text-white leading-tight">
          Sua Melhor Versão
          <br />
          <span className="text-orange-500">Começa Aqui</span>
        </h2>
        <p className="mt-6 text-lg md:text-xl max-w-2xl mx-auto text-gray-300 font-light">
          Mais que uma academia, um lugar para você superar seus limites e encontrar sua força interior.
        </p>
        <a 
          href="#planos" 
          className="mt-10 inline-block bg-orange-500 text-white font-bold text-base py-4 px-12 rounded-md uppercase tracking-wider hover:bg-orange-600 transition-all duration-300 transform hover:scale-105 shadow-lg shadow-orange-500/20"
        >
          Comece Agora
        </a>
      </div>
    </section>
  );
};

export default Hero;