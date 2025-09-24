import React from 'react';

const CallToAction: React.FC = () => {
  return (
    <section className="bg-[#181818]">
      <div className="container mx-auto px-6 py-24 text-center">
        <h2 className="text-3xl md:text-4xl font-black text-white mb-4">
          Pronto Para <span className="text-orange-500">Transformar</span> Sua Vida?
        </h2>
        <p className="text-lg text-gray-400 mb-10 max-w-2xl mx-auto font-light">
          Não espere mais. Dê o primeiro passo em direção a uma vida mais saudável e forte. Junte-se à família GYM ELITE hoje!
        </p>
        <a 
          href="#planos" 
          className="inline-block bg-orange-500 text-white font-bold text-base py-4 px-12 rounded-md uppercase tracking-wider hover:bg-orange-600 transition-all duration-300 transform hover:scale-105 shadow-lg shadow-orange-500/20"
        >
          Veja Nossos Planos
        </a>
      </div>
    </section>
  );
};

export default CallToAction;