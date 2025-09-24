import React from 'react';
import { Quote } from 'lucide-react'; // Import from lucide-react

const TestimonialCard: React.FC<{ quote: string; name: string; role: string; }> = ({ quote, name, role }) => (
  <div className="bg-[#1a1a1a] p-8 rounded-xl border border-gray-800 flex flex-col h-full">
    <div className="text-orange-500/50 mb-5">
      <Quote size={40} /> {/* Use Lucide icon */}
    </div>
    <p className="text-gray-300 italic mb-6 flex-grow font-light">"{quote}"</p>
    <div className="mt-auto">
      <p className="font-semibold text-white">{name}</p>
      <p className="text-sm text-gray-500">{role}</p>
    </div>
  </div>
);

const Testimonials: React.FC = () => {
  const testimonialsData = [
    {
      quote: "A melhor academia que já treinei! Equipamentos de ponta, ambiente incrível e profissionais super atenciosos. Recomendo de olhos fechados!",
      name: "Juliana Halter",
      role: "Membro há 2 anos"
    },
    {
      quote: "As aulas coletivas são fantásticas! Muita energia e variedade. Consegui atingir meus objetivos e fiz muitos amigos. A GYM TESTE é minha segunda casa.",
      name: "Carlos Supino",
      role: "Membro há 1 ano"
    },
    {
      quote: "O acompanhamento nutricional fez toda a diferença nos meus resultados. Uma equipe completa que se preocupa de verdade com o nosso bem-estar.",
      name: "Ana Whey",
      role: "Membro há 3 anos"
    }
  ];

  return (
    <section className="py-24 md:py-32 bg-[#121212]">
      <div className="container mx-auto px-6">
        <div className="text-center mb-16">
          <h2 className="text-4xl md:text-5xl font-black text-white">O Que Nossos Membros Dizem</h2>
          <p className="text-lg text-gray-400 mt-4 max-w-2xl mx-auto font-light">Resultados reais de pessoas reais.</p>
        </div>
        <div className="grid grid-cols-1 md:grid-cols-3 gap-8">
          {testimonialsData.map((testimonial, index) => (
            <TestimonialCard key={index} {...testimonial} />
          ))}
        </div>
      </div>
    </section>
  );
};

export default Testimonials;